# coding: utf-8
intLength = int(input())
strSentence = input()
intIndex = int(input())

strAnswer = ""
strWord = strSentence[intIndex-1]

for intIdx in range(intLength):
    if strSentence[intIdx] != strWord:
        strAnswer += "*"
    else:
        strAnswer += strWord

print(strAnswer)
