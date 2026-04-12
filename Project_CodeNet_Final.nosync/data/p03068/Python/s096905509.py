n=int(input())
s=input()
k=int(input())

moji=s[k-1]

line=[]

for i in range(n):
    line.append(s[i])

for i in range(len(s)):
    if s[i]!=moji:
        line[i]="*"

output=""

for i in range(len(line)):
    output=output+line[i]

print(output)