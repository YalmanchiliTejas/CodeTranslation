n = int(input())
s = input()
k = int(input())

a = s[k-1]
string = ''
for i in range(n):
    if s[i] == a:
        string += a
    else:
        string += '*'
        
print(string)