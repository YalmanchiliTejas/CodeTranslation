N = int(input())
S = str(input())
K = int(input())

key = S[K-1]
stk = ""
for i in S:
    if(i == key):
        stk += i
    else:
        stk += '*'
print(stk)