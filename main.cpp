#include<bits/stdc++.h>
using namespace std;
struct TIMESTAMP
{// a structure for date 
	int day;
	int month;
	int year;
};

struct DATA
{// structure for storing the data like owner id ,value ,owner name
	string ownerId;
	float value;
	string ownerName;
	string hashset;
};

struct Node
{// a structure representing the model of a node
	struct TIMESTAMP timestamp;
	struct DATA data;	
	int nodenumber;
	string nodeid;
       	struct Node *referenceNodeId;
	vector<struct Node*>childReferenceNodeId;
	string hashvalue; 
};

string encrypt(string input)
{	//function for encrypting the string input
	reverse(input.begin(),input.end());
		
	return(input);
}
string decrypt(string input)
{
	//function for decrypting the string input
	reverse(input.begin(),input.end());
	return(input);
}
float encryptv(float inp)
{
	//function for encrypting the float input 
	return(inp+100);
}
float decryptv(float inp)
{//function for decrypting the float value
	return(inp-100);
}
bool check(int nodenumber,struct Node *referenceNodeId)
{//function to check property of sum of all child node number should be less than value of parent child nodenumber
	int parentNodeNumber=referenceNodeId->nodenumber;
	int totalSumOfchildNN=0;
	int i;
	while(i<referenceNodeId->childReferenceNodeId.size())
	{
		totalSumOfchildNN=referenceNodeId->childReferenceNodeId[i]->nodenumber+totalSumOfchildNN;
	}
	
	if((parentNodeNumber-totalSumOfchildNN)<nodenumber)
	{
		return(false);

	}
	else
	{
		return(true);	
	}
	
}
 

struct Node *createNewNode(int nodenumber,struct Node *referenceNodeId,int day,int month,int year,string ownerid,float value,string ownername)
{// function for the creation of new node
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	bool flag;
	flag=check(nodenumber,referenceNodeId);
	
	if(flag==false)
	{
		cout<<"please provide correct NodeNumber it is not possible to create a new node with given Node Number"<<endl;
		return(temp);
	}
	else
	{
		temp->nodenumber=nodenumber;
		temp->referenceNodeId=referenceNodeId;
		temp->timestamp.day=day;
		temp->timestamp.month=month;
		temp->timestamp.year=year;
		temp->data.ownerId=encrypt(ownerid);	
		temp->data.value=encryptv(value);
		temp->data.ownerName=encrypt(ownername);
		referenceNodeId->childReferenceNodeId.push_back(temp);
		
		return(temp);
	}
	
}


int main()
{
	struct Node *Genesis=(struct Node*)malloc(sizeof(struct Node));
	Genesis->referenceNodeId=NULL;//Here I am making parent of Genesis Node as NULL;
	//Here I am taking Nodenumber for the genesis a hardcode value i.e 100;
	Genesis->nodenumber=100;
	//print child of node of Genesis Node
	createNewNode(40,Genesis,5,4,2018,"A",4000,"ujjwal");
	createNewNode(10,Genesis,16,9,2018,"A",1000,"ujjwal");
	
	int i=0;
	cout<<"printing the genesis value"<<endl;
	cout<<Genesis->nodenumber<<endl;
	cout<<"printing value of child Node"<<endl;
	cout<<"printing data without decryption"<<endl;
	while(i<Genesis->childReferenceNodeId.size())
	{
		cout<<Genesis->childReferenceNodeId[i]->nodenumber<<" "<<Genesis->childReferenceNodeId[i]->timestamp.day<<"/"<<Genesis->childReferenceNodeId[i]->timestamp.month<<"/"<<Genesis->childReferenceNodeId[i]->timestamp.year<<" "<<Genesis->childReferenceNodeId[i]->data.ownerId<<" "<<(Genesis->childReferenceNodeId[i]->data.value)<<" "<<Genesis->childReferenceNodeId[i]->data.ownerName<<endl;
		
		i=i+1;
	}
	i=0;
	cout<<"Data after Decryption"<<endl;
	while(i<Genesis->childReferenceNodeId.size())
	{
		cout<<Genesis->childReferenceNodeId[i]->nodenumber<<" "<<Genesis->childReferenceNodeId[i]->timestamp.day<<"/"<<Genesis->childReferenceNodeId[i]->timestamp.month<<"/"<<Genesis->childReferenceNodeId[i]->timestamp.year<<" "<<decrypt(Genesis->childReferenceNodeId[i]->data.ownerId)<<" "<<decryptv(Genesis->childReferenceNodeId[i]->data.value)<<" "<<decrypt(Genesis->childReferenceNodeId[i]->data.ownerName)<<endl;
		
		i=i+1;
	}

	return(0);
}