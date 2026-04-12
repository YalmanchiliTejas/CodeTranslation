#B - *e**** ********e* *e****e* ****e**
n = int(input())
s = list(input())
k = int(input())
kome = s[k-1]
for i in range(n):
    if s[i] != kome:
        s[i] = '*'
print(''.join(s))