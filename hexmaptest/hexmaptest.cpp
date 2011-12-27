// map::insert
#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main ()
{
  map<int, unsigned char> mymap;
  map<int, unsigned char>::iterator it;
  pair<map<int, unsigned char>::iterator,bool> ret;

  // first insert function version (single parameter):
  mymap.insert ( pair<int,unsigned char>(0x000000,0x55) );
  mymap.insert ( pair<int,unsigned char>(0x000020,0x32) );
  mymap.insert ( pair<int,unsigned char>(0x002000,0xA2) );
  mymap.insert ( pair<int,unsigned char>(0x0F0000,0x01) );
  ret=mymap.insert ( pair<int,unsigned char>(0x000000,0xAA) ); 
  if (ret.second==false)
  {
    cout << "element '0x000000' already existed";
    cout << " with a value of "; //<< ret.first->second << endl;
    cout << "0x" << setw(2) << static_cast<unsigned short>(ret.first->second) << endl;
  }

  // second insert function version (with hint position):
  it=mymap.begin();
  mymap.insert ( pair<int,unsigned char>(0x000001,0x55) );  // max efficiency inserting
  mymap.insert ( pair<int,unsigned char>(0x000003,0x22) );  // no max efficiency inserting

  // showing contents:
  cout << "mymap contains:\n";
  for ( it=mymap.begin() ; it != mymap.end(); it++ )
    cout << uppercase << "0x" << setw(8) << setfill('0') << hex << (*it).first << " => " << "0x" << setw(2) << static_cast<unsigned short>((*it).second) << endl;

  return 0;
}
