#include"CAccessData.h"
#include<cstring>
struct StudentData{
	string SID;
	string SName;
	string SClass;
};
class CClassData : public CAccessData
{
private:
	StudentData * lpsdata[100];
	string ClassName;
public:
    int length;
    CClassData(string c);
	virtual void add(string id, string name, string cla);
	virtual void remove(string id);
	void Sort();
	void FileWrite(string fileName);
	int  check(string id);
	void Show();
	void nulll();
	int getlength();
	string getClassName();
		~CClassData(){
	}
};

