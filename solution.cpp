class Solution {
public:
    vector<vector<int>> in_grid;

    Node constr_rec(int begin_y, int begin_x, int dim) {
            Node* topleft = new Node;
            Node* topright = new Node;
            Node* bottomleft = new Node;
            Node* bottomright = new Node;
        if (dim == 2) {
            int tl = in_grid[begin_y][begin_x];
            int tr = in_grid[begin_y][begin_x+1];
            int bl = in_grid[begin_y+1][begin_x];
            int br = in_grid[begin_y+1][begin_x+1];
            if (tl == tr && tl == bl && tl == br) {
                return Node(tl, true);
            }
            *topleft = Node(tl, true);
            *topright = Node(tr, true);
            *bottomleft = Node(bl, true);
            *bottomright = Node(br, true);
            return Node(true, false, topleft, topright, bottomleft, bottomright);
        } else {
            *topleft = constr_rec(begin_y, begin_x, dim/2);
            *topright = constr_rec(begin_y, begin_x+dim/2, dim/2);
            *bottomleft = constr_rec(begin_y+dim/2, begin_x, dim/2);
            *bottomright = constr_rec(begin_y+dim/2, begin_x+dim/2, dim/2);
            if (topleft->val == topright->val && topleft->val == bottomleft->val && topleft->val == bottomright->val && topleft->isLeaf && topright->isLeaf && bottomleft->isLeaf && bottomright->isLeaf) {
                return Node(topleft->val, true);
            } else {
                return Node(true, false, topleft, topright, bottomleft, bottomright);
            }
        }
    }

    Node* construct(vector<vector<int>>& grid) {
        Node* temp = new Node;
        int size = grid.size();
        if (size == 1) {
            *temp = Node(grid[0][0], true);
        } else {
            in_grid = grid;
            *temp = constr_rec(0, 0, size);
        }
        return temp;
    }
};
