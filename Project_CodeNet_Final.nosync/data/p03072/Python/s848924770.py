N = int(input())
inputlist = input().split()
H_list = []
for H in inputlist:
    H_list.append(int(H))
    
answer = 0
clearFrag = 0
for i in range(len(H_list)):
    if i == 0:
        answer += 1
    else:
        for prior in range(i):
            if H_list[prior] > H_list[i]:
                break
            else:
                clearFrag += 1
        if clearFrag == i:
            answer += 1
        clearFrag = 0

print(answer)