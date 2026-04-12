wordSize = int(input())
word= str(input())
removePosition = int(input())
reword=''
for i in range(wordSize):
    if(word[i]!=word[removePosition-1]):
        reword +=(str("*"))
    else:
        reword+=(word[i])
print(reword)