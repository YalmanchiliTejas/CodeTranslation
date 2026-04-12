n = int(input())
h_list = [int(i) for i in input().split()]

count = 0
for i in range(len(h_list)):
    if max(h_list[:i+1]) == h_list[i]:
        count += 1
print(count)
    
