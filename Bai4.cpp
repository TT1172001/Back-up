#include <iostream>
#include <vector>
#include<string>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef struct Transaction{
	string from_account;
	string to_account;
	int money;
	string time;
	string atm;
	Transaction(string fa,string ta,int m,string t, string a)
	{
		from_account=fa;
		to_account=ta;
		money=m;
		time=t;
		atm=a;
	}
};

int main(int argc, char** argv) {
	vector<string> v;
	vector<Transaction> trans;
	int n;
	
	
	while(1){
		string s;
		getline(cin,s);
		if(strcmp(s.c_str(),"#")==0) break;
		v.push_back(s);
	}
	n=v.size();
	string space_delimiter = " ";
	
	for(int i=0;i<n;i++){
		vector<string> words;
	    size_t pos = 0;
	    while ((pos = v[i].find(space_delimiter)) != string::npos) {
	        words.push_back(v[i].substr(0, pos));
	        v[i].erase(0, pos + space_delimiter.length());
   	 	}
   	 	words.push_back(v[i]);
   	 	
   	 	
		
		Transaction tran=Transaction(words[0],words[1],atoi(words[2].c_str()),words[3],words[4]);
		trans.push_back(tran);	
	}
	
	while(1){
		string s;
		getline(cin,s);
		if(strcmp(s.c_str(),"#")==0) break;
		string time1,time2;
		int max=0;
   	 	time1=s.substr(18,8);
   	 	time2=s.substr(27,8);
   	 	for(int i=0;i<trans.size();i++){
			if(strcmp(time1.c_str(), trans[i].time.c_str())<=0 && strcmp(time2.c_str(), trans[i].time.c_str())>=0){
				if(max<trans[i].money) max=trans[i].money;
			}
		}
	cout << max << endl;
	}


	
	
    
	return 0;
}

