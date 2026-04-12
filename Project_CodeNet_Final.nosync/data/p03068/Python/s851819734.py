
def main():
    C=[]
    for i in range(3):
        C.append((input()))

    line = list(C[1])

    for i in range(int(C[0])):
        if line[i] != line[int(C[2])-1]:
            line[i] = "*"

    ans = ""
    for i in line:
        ans +=i

    return ans

print(main())