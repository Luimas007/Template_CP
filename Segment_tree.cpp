#include<bits/stdc++.h>
using namespace std ;
#define ll long long

class SegmentTree {
public:
    vector<ll> v, seg;
    ll n;

    SegmentTree(vector<ll> &arr) {
        n = arr.size();
        v = arr;
        seg.resize(4 * n, LLONG_MAX);
    }

    void build_Tree(ll indx, ll lo, ll hi) {
        if (lo == hi) {
            seg[indx] = v[lo];
            return;
        } else {
            ll mid = lo + (hi - lo) / 2;
            build_Tree(2 * indx + 1, lo, mid);
            build_Tree(2 * indx + 2, mid + 1, hi);
            seg[indx] = min(seg[2 * indx + 1], seg[2 * indx + 2]);
        }
    }

    void build() {
        build_Tree(0, 0, n - 1);
    }

    ll query_Tree(ll indx, ll lo, ll hi, ll q_lo, ll q_hi) {
        if (q_lo <= lo && hi <= q_hi) {
            return seg[indx];
        } else if (q_hi < lo || q_lo > hi) {
            return LLONG_MAX;
        } else {
            ll mid = lo + (hi - lo) / 2;
            ll left_val = query_Tree(2 * indx + 1, lo, mid, q_lo, q_hi);
            ll right_val = query_Tree(2 * indx + 2, mid + 1, hi, q_lo, q_hi);
            return min(left_val, right_val);
        }
    }


    ll query(ll q_lo, ll q_hi) {
        return query_Tree(0, 0, n - 1, q_lo, q_hi);
    }


    void update_tree(ll node, ll lo, ll hi, ll val_indx, ll val) {
        if (lo == hi && lo == val_indx) {
            seg[node] = val;
            v[val_indx] = val;
            return;
        }

        ll mid = lo + (hi - lo) / 2;
        if (val_indx <= mid) {
            update_tree(2 * node + 1, lo, mid, val_indx, val);
        } else {
            update_tree(2 * node + 2, mid + 1, hi, val_indx, val);
        }

        seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    }

    void update(ll val_indx, ll val) {
        update_tree(0, 0, n - 1, val_indx, val);
    }
};



int main(){
return 0 ;
}
