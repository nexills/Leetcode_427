# Leetcode_427
My C++ solution for leetcode Q427

# Description (as from leetcode)
Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

# Solution
Recursive Solves the problem by recursively calling an auxiliary function on each part of the matrix, simplifying the solution whenever all the children nodes have the same binary values.

