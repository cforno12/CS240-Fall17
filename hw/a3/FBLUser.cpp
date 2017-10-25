//libraries
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
//user headers
#include "FBLUser.h"
#include "FBLPostLL.h"

FBLUser::FBLUser(){
    last_name = "";
    first_name = "";
    password = "";
    user_id = "";
    feed = new FBLPostLL();
    wall = new FBLPostLL();
    friends.clear();
}

FBLUser::~FBLUser(){
    if(wall){
        delete wall;
    }
    if(feed){
        delete feed;
    }
    friends = vector<FBLUser*>();
}

//GETTERS
string FBLUser::get_first_name(){
    return first_name;
}
string FBLUser::get_last_name(){
    return last_name;
}
string FBLUser::get_password(){
    return password;
}
string FBLUser::get_user_id(){
    return user_id;
}

FBLPostLL* FBLUser::get_feed(){
    return feed;
}

FBLPostLL* FBLUser::get_wall(){
    return wall;
}
//SETTERS
void FBLUser::set_first_name(string fn){
    first_name = fn;
}
void FBLUser::set_last_name(string ln){
    last_name = ln;
}
void FBLUser::set_password(string pw){
    password = pw;
}
void FBLUser::set_user_id(string ui){
    user_id = ui;
}
//OTHER FUNCTIONS
void FBLUser::print_user(){
    cout << "User: " << user_id << endl;
    cout << "Password: " << password << endl;
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
}

void FBLUser::post(string p){
    FBLPost* post_obj = new FBLPost(p);
    FBLPostNode* post_node = new FBLPostNode(post_obj);
    wall->add(post_node);
    for (unsigned int i = 0; i < friends.size(); i++) {
        friends[i]->get_feed()->add(post_node);
    }
}

void FBLUser::read(){
    feed->read();
}

void FBLUser::print_feed(){
    feed->print_posts();
}

void FBLUser::print_wall(){
    wall->print_posts();
}

void FBLUser::make_friend(FBLUser* u){
	bool add = true;
	for (unsigned int i = 0; i < friends.size(); i++) {
		if(friends[i]->get_user_id() == u->get_user_id()){
			add = false;
		}
	}
	if(add){
		friends.push_back(u);
	}
}

void FBLUser::print_friends(){
    for (unsigned  int i = 0; i < friends.size(); i++){
        cout << "\t\t" <<friends[i]->get_first_name() << " " << friends[i]->get_last_name() << endl;
    }
}
