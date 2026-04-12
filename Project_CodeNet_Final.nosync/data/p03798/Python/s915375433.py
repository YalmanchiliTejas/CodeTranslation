import sys

def rev(t):
    if t == "S":
        return "W"
    else:
        return "S"

N = int(input())

s = input()

for p in range(2):

    for q in range(2):

        lis = []

        if p == 0:
            lis.append("S")
        else:
            lis.append("W")
        if q == 0:
            lis.append("S")
        else:
            lis.append("W")

        for i in range(N-2):

            if lis[-1] == "S":
                if s[i+1] == "o":
                    lis.append(lis[i])
                else:
                    lis.append(rev(lis[i]))

            else:
                if s[i+1] == "o":
                    lis.append(rev(lis[i]))
                else:
                    lis.append(lis[i])

        flag = True
        
        if lis[0] == "S":
            if s[0] == "o" and lis[-1] != lis[1]:
                flag = False
            elif s[0] == "x" and lis[-1] == lis[1]:
                flag = False

        else:
            if s[0] == "o" and lis[-1] == lis[1]:
                flag = False
            elif s[0] == "x" and lis[-1] != lis[1]:
                flag = False

        
        if lis[-1] == "S":
            if s[-1] == "o" and lis[-2] != lis[0]:
                flag = False
            elif s[-1] == "x" and lis[-2] == lis[0]:
                flag = False

        else:
            if s[-1] == "o" and lis[-2] == lis[0]:
                flag = False
            elif s[-1] == "x" and lis[-2] != lis[0]:
                flag = False

        if flag:
            print ("".join(lis))
            sys.exit()

print (-1)
           
