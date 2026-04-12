import numpy as np
n = int(input())
a = np.array(list(map(int,input().split())))
ans = 0
while a[np.argmax(a)] >= n:
    temp = a[np.argmax(a)] // n
    ans += temp
    a += temp
    a[np.argmax(a)] -= (n+1) * temp
print(ans)