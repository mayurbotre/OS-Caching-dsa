#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        class node {
            public:
                int key;
                int val;
                node* next;
                node* prev;
                node(int _key, int _val){
                    key=_key;
                    val=_val;
                }
        };

        node* head= new node(-1, -1);
        node* tail = new node(-1, -1);

        int cap;

        unordered_map<int, node*> mp;

        LRUCache(int capacity){
            cap=capacity;
            head->next=tail;
            tail->prev=head;
        }

        void addnode(node* newnode){
            node* tmp = head->next;
            newnode->next=tmp;
            newnode->prev=head;
            head->next=newnode;
            tmp->prev=newnode;
        }

        void deletenode(node* delnode){
            node* deleteprev = deletenode->prev;
            node* deletenext = deletenode->next;
            deleteprev->next=deletenext;
            deletenext->prev=deleteprev;
            free(delnode);
        }

        int get(int key_){
            if(mp.find(key_)!=mp.end()){
                node* resnode=mp[key_];
                int res=resnode->val;
                mp.erase(key_);
                deletenode(resnode);
                addnode(resnode);
                mp[key_]=head->next;
                return res;
            }
        }

        void put(int key_, int value){
            if(mp.find(key_)!=mp.end()){
                node* existingnode = mp[key_];
                mp.erase(key_);
                deletenode(existingnode);
            }
            if(mp.size()==cap){
                mp.erase(tail->prev->key);
                deletenode(tail->prev);
            }
            addnode(new node(key_, value));
            mp[_key]=head->next;
        }
}