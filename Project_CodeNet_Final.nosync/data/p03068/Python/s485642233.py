i = [input() for i in range(3)]
#print(i)
l = []
count = 0
for n in i:
    if count != 1:
        n = int(n)
    l.append(n) 
    count += 1
#print(l)
s = l[1]
#print(type(s[l[2]]))

for i in range(l[0]):
    
    if s[i] != s[l[2]-1]:
        s = list(s)
        s[i] = '*'
        s = "".join(s)
        #s = s[:i+1] + '*' + s[i+2:]
print(s)
