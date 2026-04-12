# coding: utf-8
# Your code here!

A, B, AB, num_A, num_B = map(int, input().rstrip().split(' '))

min_cost = A * num_A + B * num_B
min_cost = min(min_cost, AB * 2 * max(num_A, num_B))
if num_A == num_B:
    min_cost = min(min_cost, AB * (num_A + num_B))
elif num_A > num_B:
    min_cost = min(min_cost, A * (num_A - num_B) + AB * 2 * num_B)
elif num_A < num_B:
    min_cost = min(min_cost, B * (num_B - num_A) + AB * 2 * num_A)
    
print(min_cost)