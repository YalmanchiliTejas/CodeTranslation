n = int(input())
a = [int(x) for x in input().split()]

cou = 1 
high = [a[0]]

for i in range(n-1):
    mmhigh = max(high)
    aa = a[i + 1]
    
    if mmhigh <= aa:
        high.append(aa)
        cou += 1
    else:
        pass
      
print(cou)