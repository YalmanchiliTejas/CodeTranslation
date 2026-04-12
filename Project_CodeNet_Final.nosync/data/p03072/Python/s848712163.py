n = int(input())
h_list = [int(i) for i in input().split()]
count = sum(max(j) == j[-1] for i in range(1, n+1) for j in [h_list[0:i]])
print(count)