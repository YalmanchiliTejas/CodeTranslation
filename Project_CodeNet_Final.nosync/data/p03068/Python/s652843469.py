from sys import stdin
input=[]
for i in range(3):
    input.append(stdin.readline().rstrip())

input[0]=int(input[0])
input[2]=int(input[2])
flag=input[1][input[2]-1]
output=""
for i in range(input[0]):
    if input[1][i]!=flag:
        #input[1][i]="*"
        output+="*"
    else:
        output+=flag
print(output)