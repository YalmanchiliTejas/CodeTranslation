H,W=map(int,input().split())
a=[input() for _ in range(H)]
answers1=[]
for h in range(H):
    a1=a[h]
    if '#' in a1:
        answers1.append(a1)
answers2=['' for _ in range(len(answers1[0]))]
for answer in answers1:
    for n in range(len(answer)):
        answers2[n]+=answer[n]
answers=[]
for answer in answers2:
    if '#' in answer:
        answers.append(answer)
for x in range(len(answers[0])):
    kotae=''
    for y in range(len(answers)):
        kotae+=answers[y][x]
    print(kotae)
    