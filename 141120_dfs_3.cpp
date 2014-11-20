#include <iostream>
#include <cstdlib>
using namespace std;

int arr[7][7]={
		{0,1,1,0,0,0,0},
		{1,0,0,0,1,0,0},
		{1,0,0,0,0,0,0},
		{0,0,0,0,0,0,1},
		{0,1,0,0,0,1,0},
		{0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0}
		};

bool visited[7] = {false};
bool found = false;
string findpath="";

void dfs(int s, int e) //0, 1 = 0 2 1
{
	if(s==e)
	{
		found = true;
		cout<<"========================="<<endl;
		cout<<"�����| ! ���|�� : "; 
	}
	if(found)
	{
		return;
	}
	visited[s] = true;
	for(int w = 0; w<7; w++)
	{
		if(arr[s][w]==1)
		{
			if(!visited[w])
			{
				dfs(w,e);
				if(found)
				{
					findpath+=(w+'0');
					break;
				}
			}
		}
	}
}

void init()
{
	int s,e;
	cout<<"�п�J�_�I : ";
	cin>>s;
	cout<<"�п�J���I : ";
	cin>>e;
	dfs(s,e);
	if(!found)
	{
		cout<<"�䤣����|�C"; 
	}
	else
	{
		findpath+=(s+'0');
		//cout<<s;
		for(int i = 0; i<findpath.length(); i++)
		{
			cout<<findpath.substr((findpath.length()-1-i), 1)<<",";
		}
	}
}

int main()
{
	init();
}
