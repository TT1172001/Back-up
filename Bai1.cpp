#include <iostream>
#include <vector>
#include <string>
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
	string s1 = "?total_money_transaction?";
    getline(cin,s1);
    string s2 = "#";
    getline(cin,s2);
	
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
	int sum=0;
	for(int i=0;i<trans.size();i++){
		sum+=trans[i].money;
	}
	cout<<sum;
    
	return 0;
}
