

N = int(input())
S = str(input())
K =int(input())

K_char = S[K-1]
ans = ''
for i in S:
    if i == K_char:
        ans += i
    elif  i != K_char:
        ans += '*'
        
print(ans)