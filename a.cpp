#include <bits/stdc++.h>
using namespace std;

// structure of a node of binary tree
struct Node {
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void print(Node *root,int n1,int n2,vector<int> ans,int flag){

    if(root==NULL){
        return;
    }

    if(root->data == n1|| root->data == n2){
        ans.push_back(root->data);
        if(flag == 2){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
        }

        else{
            for(int i=ans.size()-1;i>=0;i--){
                cout<<ans[i]<<" ";
            }
        }
        return;
    }

    else{
        ans.push_back(root->data);
        print(root->left,n1,n2,ans,flag);
        print(root->right,n1,n2,ans,flag);
    }
}

Node* lca(Node* root,int n1,int n2)
{
    if(root==NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node *l = lca(root->left,n1,n2);
    Node *r = lca(root->right,n1,n2);

    if(l!=NULL && r!=NULL){
        return root;
    }

    if(l==NULL && r!=NULL){
        return r;
    }

    if(l!=NULL && r==NULL){
        return l;
    }
}

//there may be two case:
// 1) WHEN THE LEFT AND RIGHT BOTH EXITS
// 2) WHEN ONLY ONE OF THEM EXITS.


void cal(Node *root,int n1,int n2)
{
    Node *la = lca(root,n1,n2);
    cout<<la->data<<endl;

    vector<int> ans1;
    vector<int> ans2;
    printf("\n printing the path here \n");
    ans1.push_back(la->data);
    print(la->left,n1,n2,ans1,1);
    print(la->right,n1,n2,ans2,2);
}



int main()
{
    // binary tree formation
    struct Node* root = getNode(0);
    root->left = getNode(1);
    root->left->left = getNode(3);
    root->left->left->left = getNode(7);
    root->left->right = getNode(4);
    root->left->right->left = getNode(8);
    root->left->right->right = getNode(9);
    root->right = getNode(2);
    root->right->left = getNode(5);
    root->right->right = getNode(6);

    int node1 = 7;
    int node2 = 8;
    cal(root, node1, node2);

    return 0;
}
