n = int(input())
s = str(input())
k = int(input())

c = s[k-1]

output = []
for i in range(n):
        if(s[i] == c):
                output.append(c)
        else:
                output.append("*")
print(''.join(output))