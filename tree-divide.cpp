/*
All submissions for this problem are available.Given a tree with n nodes. 
Split it into 3 parts such that all the three parts are connected components in original graph and each node is 
exactly present in one of the parts and the following function is minimised: Let s1,s2,s3 be the sizes of the 3 
parts (or connected components) then 
f=|s1−s2|+|s2−s3|+|s1−s3|

Also calculate the number of ways of splitting the tree. Two ways are considered different if different sets of edges is removed.
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>
#include <memory>
#include <list>

using namespace std;

class Node {
    public:
        Node(int i) : info(i) { }
        int info;
        int totalChildren = 0;
        list<shared_ptr<Node>> children;
        friend ostream& operator << (ostream& os, const Node& node) {
            os << "id: " << info << " tc: " << totalChildren << endl;
            return os;
        }
};

class Tree {
    public:
        shared_ptr<Node> root;
        void add(int src, int dest) {
            Node parent(src);
            Node child(dest);
            parent.children.push_back(make_shared<Node>(child));
            if (root == nullptr) {
                root = make_shared<Node>(parent);
            }
        }

        int countChildren() {
            calc(root);
        }

        void print() {

        }
    private:
        int calc(shared_ptr<Node> root) {
            if (root != nullptr) {
                for(auto& child : children) {
                    root->totalChildren = calc(child) + 1;
                    return root->totalChildren;
                }
            } else {
                root->totalChildren = 0;
                return 0
            }
        }

        void print(shared_ptr<Node> root) {
            if (root != nullptr) {
                cout << root->info << "->";
                for(auto& child:children) {
                    print(root->child);
                    cout << *root->child << ",";
                }
                cout << endl;
            }
        }

};

int main() {
    string nVertices;
    stringstream ss;
    vector<pair<int, int>> edges;

    getline(cin, nVertices);
    ss << nVertices;
    int v;
    ss >> v;
    for (int i = 0; i < v; ++i) {
        string line;
        stringstream ss;
        getline(cin, line);
        ss << line;
        int t1, t2;
        ss >> t1 >> t2;
        pair<int,int> p {t1, t2};
        edges.push_back(p);
    }
}

