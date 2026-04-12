N = int(input())
S = input()
K = int(input())

char = S[K - 1]
rst = ""
for s in S : 
    if s == char : 
        rst += s
    else : 
        rst += "*"
print(rst)