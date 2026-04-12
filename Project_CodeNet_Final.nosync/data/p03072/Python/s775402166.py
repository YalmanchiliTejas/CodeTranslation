#ABC124

n = int(input())
h = list(map(int,input().split()))
count = 0
for i in range(1,n+1):
    if  max(h[:i]) == h[:i][-1]:
        count += 1
        
print(count)