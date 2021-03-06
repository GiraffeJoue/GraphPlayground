/* 
 * File:   test_edge_constructor.cpp
 * Author: Kyle McGrath
 *
 * Created on October 15, 2017, 11:05 AM
 */


#include <stdlib.h>
#include <iostream>
#include "../../graph/node/node.h"
#include "../../graph/edge/edge.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;

void test1() {
    std::cout << "test_edge_constructor test 1" << std::endl;
    
    try {
        node* n1 = new node(2);
        node* n2 = new node(3);
        edge e(n1, n2);
        if(e.first->value != 2 || e.second->value != 3)
            cout << "%TEST_FAILED% time=0 testname=test1 message=node constructor did not assign values correctly" <<  endl;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test1 message=node constructor caused error" <<  endl;
        
    }
}

void test2() {
    std::cout << "test_edge_constructor test 2" << std::endl;
    
    try {
        node* n1 = new node(2);
        node* n2 = new node(3);
        edge e1(n1, n2);
        edge e2(e1);
        if(e2.first->value != 2 || e2.second->value != 3)
            cout << "%TEST_FAILED% time=0 testname=test2 message=node copy constructor did not assign values correctly" <<  endl;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test2 message=node copy constructor caused error" <<  endl;
    }
    
}

void test3() {
    std::cout << "test_edge_constructor test 3" << std::endl;
    
    try {
        node* n1 = new node(247);
        node* n2 = new node(-29983);
        edge* e1 = new edge(n1, n2);
        edge* e2 = new edge(*e1);
        
        if(e1->first->value != 247 || e1->second->value != -29983)
            cout << "%TEST_FAILED% time=0 testname=test3 message=node constructor did not assign values correctly" <<  endl;
        if(e2->first->value != 247 || e2->second->value != -29983)
            cout << "%TEST_FAILED% time=0 testname=test3 message=node copy constructor did not assign values correctly" <<  endl;
        

        delete e1;
        delete e2;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test3 message=node copy constructor caused error" <<  endl;
    }
    
}

void test4() {
    std::cout << "test_edge_constructor test 4" << std::endl;
    
    try {
        edge* e1 = new edge(5, -99993);
        if(e1->first->value != 5 || e1->second->value != -99993)
            cout << "%TEST_FAILED% time=0 testname=test4 message=convenient node constructor did not assign values correctly" <<  endl;
        delete e1;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test4 message=convenient node constructor caused error" <<  endl;
    }
    
}

void test5() {
    std::cout << "test_edge_constructor test 5" << std::endl;
    
    try {
        int x = int(5.0/9.0);
        int y = int(-99993.0/476.0);
        edge* e1 = new edge(5.0/9.0, -99993.0/476.0);
        if(e1->first->value != x || e1->second->value != y)
            cout << "%TEST_FAILED% time=0 testname=test5 message=convenient node constructor did not assign values correctly" <<  endl;
        delete e1;
    } catch(exception e) {
        cout << "%TEST_FAILED% time=0 testname=test5 message=convenient node constructor caused error" <<  endl;
    }
    
}

int main(int argc, char** argv) {
    
    auto clock = chrono::steady_clock();
    
    auto suiteStart = clock.now();
    cout << "%SUITE_STARTING% test_edge_constructor" << endl;
    cout << "%SUITE_STARTED%" << endl;

    auto start = clock.now();
    cout << "%TEST_STARTED% test1 (test_edge_constructor)" << endl;
    test1();
    auto end = clock.now();
    auto dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test1 (test_edge_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test2 (test_edge_constructor)" << endl;
    test2();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test2 (test_edge_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test3 (test_edge_constructor)" << endl;
    test3();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test3 (test_edge_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test4 (test_edge_constructor)" << endl;
    test4();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test4 (test_edge_constructor)" << endl;
    
    start = clock.now();
    cout << "%TEST_STARTED% test5 (test_edge_constructor)" << endl;
    test5();
    end = clock.now();
    dur = chrono::duration<double>(end-start);
    cout << "%TEST_FINISHED% time=" << dur.count() << " test5 (test_edge_constructor)" << endl;
    
    auto suiteEnd = clock.now();
    auto suiteDur = chrono::duration<double>(suiteEnd-suiteStart);
    std::cout << "%SUITE_FINISHED% time=" << suiteDur.count() << std::endl;

    return (EXIT_SUCCESS);
}

