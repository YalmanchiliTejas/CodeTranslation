n = int(input())
h_list = [int(i) for i in input().split()]
whole_list = [h_list[0:i] for i in range(1, n+1)]
count = sum(max(j) == j[-1] for i in range(1, n+1) for j in [h_list[0:i]])
print(count)