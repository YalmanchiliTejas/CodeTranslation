n = int(input())
h = [int(i) for i in input().split()]

count =0 
for i in range(n):
    j = h[:(i+1)]
    if max(j) == h[i]:
        count+=1
print(count)
            