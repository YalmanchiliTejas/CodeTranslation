b = [10000]*26

def check(s):
    tmp = [0]*26
    for i in s:
        tmp[ord(i)-97] += 1
    
    for i in range(26):
        b[i] = min(b[i],tmp[i])
    

n = int(input())

for _ in range(n):
    check(input())


ans = ""

for i in range(26):
    ans += chr(97+i)*b[i]

print(ans)