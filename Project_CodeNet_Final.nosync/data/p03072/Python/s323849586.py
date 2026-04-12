n = int(input())
h_list = list(map(int,input().split()))
count = 0
for i in range(n):
    if max(h_list[:i+1]) == h_list[i]:
        count+= 1
print(count)