n = int(input())
s = input()
k = int(input())

s_list = list(s)


#print(s[0])

for i in range(n):
    if(s[i] != s[k-1]):
        #print(s[i])
        s_list[i] = '*'

answer = "".join(s_list)
print(answer)