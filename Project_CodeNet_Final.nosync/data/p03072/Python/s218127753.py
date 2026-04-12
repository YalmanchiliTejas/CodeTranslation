n=int(input())
h = [int(x) for x in input().split()]
count=1

for i in range(1,n):
    if h[i] == max(h[:i+1]):
        count+=1
print(count)