N = int(input())
S = input()
K = int(input())
result = ''
c = S[K - 1]

for s in S:
    
    if(s != c):
        result += '*'
    
    else:
        result += s

print(result)