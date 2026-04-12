n = input()
word = input()
a= input()
b=0
text=''
x=word[int(a)-1]
 
for i in range(int(n)):
    if word[i] == x:
         text = text + x
    else:
        text = text + '*'
print(text)