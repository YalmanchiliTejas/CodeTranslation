N = int(input())
S = input()
K = int(input())

a = S[K-1]

aa = S.split(a)
output = ''
for i in range(len(aa)):
    output += '*' * len(aa[i])+a

print(output[:-1])