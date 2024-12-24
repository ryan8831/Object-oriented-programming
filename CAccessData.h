#include<iostream>
using namespace std;
class CAccessData {
public:
    virtual	void add(string SID, string SName, string SClass)=0;
    virtual	void remove(string SID)=0;

};
