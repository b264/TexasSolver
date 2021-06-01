//
// Created by bytedance on 20.4.21.
//
#include "tools/utils.h"
void exchange_color(vector<float>& value,vector<PrivateCards> range,int rank1,int rank2){
#ifdef DEBUG
    if(value.size() != range.size()) throw runtime_error("size problem");
    if(rank1 >= rank2) throw runtime_error("rank value problem");
#endif
    if(value.empty())return;
    vector<int> self_ind = vector<int>(value.size());
    int privateint2ind[52 * 52 * 2];
    for(int i = 0;i < range.size();i ++){
        PrivateCards& pc = range[i];
        int card1 = pc.card1;
        int card2 = pc.card2;
        if(card1 > card2){
            int tmp = card1;
            card1 = card2;
            card2 = tmp;
        }
        self_ind[i] = card1 * 52 + card2;

        if(card1 % 4 == rank1) card1 = card1 - rank1 + rank2;
        else if(card1 % 4 == rank2) card1 = card1 - rank2 + rank1;

        if(card2 % 4 == rank1) card2 = card2 - rank1 + rank2;
        else if(card2 % 4 == rank2) card2 = card2 - rank2 + rank1;

        if(card1 > card2){
            int tmp = card1;
            card1 = card2;
            card2 = tmp;
        }
        privateint2ind[card1 * 52 + card2] = i;
    }

    for(int i = 0;i < range.size();i ++) {
        if(self_ind[i] == -1) continue;
        int ind = privateint2ind[self_ind[i]];
        //cout << range[i].toString() << " ";
        //cout << range[ind].toString() << endl;
        if(ind != i){
            self_ind[ind] = -1;
            float tmp = value[i];
            value[i] = value[ind];
            value[ind] = tmp;
        }
    }
    //throw runtime_error("exiting...here...");
}

