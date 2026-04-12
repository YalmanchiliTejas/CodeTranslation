n = int(input())
a = list([int(input()) for i in range(n)])
a.sort()
import copy
b = copy.deepcopy(a)
a.reverse()

ans = 0

if(n%2==0):
    cnt = 0
    while(cnt!=n):
        if(cnt==0):
            initn = a[cnt]
            pre = a[cnt]
            cnt += 1

        elif(cnt == n-1):
            if(cnt%2 == 0):
                ans += abs(initn - a[cnt//2])
                pre = a[cnt//2]
            else:
                ans += abs(initn - b[cnt//2])
                pre = b[cnt//2]
            cnt += 1
            
        else:
            if(cnt%2 == 0):
                ans += abs(pre - a[cnt//2])
                pre = a[cnt//2]
            else:
                ans += abs(pre - b[cnt//2])
                pre = b[cnt//2]
            cnt += 1
    print(ans)
else:
    cnt = 0
    while(cnt!=n):
        if(cnt==0):
            initn = a[cnt]
            pre = a[cnt]
            cnt += 1

        elif(cnt == n-1):
            if(cnt%2 == 0):
                ans += abs(initn - a[cnt//2])
                pre = a[cnt//2]
            else:
                ans += abs(initn - b[cnt//2])
                pre = b[cnt//2]
            cnt += 1
            
        else:
            if(cnt%2 == 0):
                ans += abs(pre - a[cnt//2])
                pre = a[cnt//2]
            else:
                ans += abs(pre - b[cnt//2])
                pre = b[cnt//2]
            cnt += 1
    ans1 = ans
    ans = 0
    cnt = 0
    while(cnt!=n):
        if(cnt==0):
            initn = b[cnt]
            pre = b[cnt]
            cnt += 1

        elif(cnt == n-1):
            if(cnt%2 == 0):
                ans += abs(initn - b[cnt//2])
                pre = b[cnt//2]
            else:
                ans += abs(initn - a[cnt//2])
                pre = a[cnt//2]
            cnt += 1
            
        else:
            if(cnt%2 == 0):
                ans += abs(pre - b[cnt//2])
                pre = b[cnt//2]
            else:
                ans += abs(pre - a[cnt//2])
                pre = a[cnt//2]
            cnt += 1
    
    print(max(ans1,ans))