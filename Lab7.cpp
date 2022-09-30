//Danny Radosevich
//Lab 7
//Written for UWYO COSC 2030

#include<iostream>

using namespace std;

#define HASHSIZE 73
//whatever the size of your array woulld be

int example(string toHash);
int hasher(string toHash);
int main()
{
  string input = "";
  bool control = true;
  while(control)
  {
    cout<<"Enter somthing to hash, STOP to stop"<<endl;
    cin>>input;
    if(input=="STOP")
    {
      control =false;
    }
    else
    {
      cout<<"Ward's hash returned "<<to_string(example(input))<<endl;
      cout<<"Your hash returned "<<to_string(hasher(input))<<endl;

    }
  }
  return 0;
}
int example(string toHash)
{
  int i; long int val=0;
  for (i=0; i<=toHash.size(); i++)
  {
    val+= (int)toHash[i] * (i*i);
  }
  //divide by the size of the array to make sure you always get something within bounds
  return val%HASHSIZE;
}
int hasher(string toHash)
{
  int i; long int val=0;
  for (i=0; i<=toHash.size(); i++)
  {
    val+= (int)toHash[i];
  }
  val*=13532;
  val /= 51;
  return val%HASHSIZE;
}
