n=int(input())
l = list(map(int, input().split()))
#print(l)
x = 0
for i in range(n):
    a = max(l[0:i+1])
    #print(l[i],a)
    if l[i] >= a:
        x += 1
print(x)





