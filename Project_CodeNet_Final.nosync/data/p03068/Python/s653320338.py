
N = int(input())
s = input()
K = int(input())
letter = s[K-1]
for i in range(N):
    if s[i] != letter:
        s = s[:i] + '*' + s[i+1:]
        
print(s)
    



