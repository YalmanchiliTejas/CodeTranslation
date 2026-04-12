n = int(input())
h = list(map(int, input().split()))

sum=1
for i in range(1, n):
        flag = True
        for j in range(0, i):
                if(h[j] > h[i]):
                        flag = False
        if(flag):
                sum+=1
print(sum)