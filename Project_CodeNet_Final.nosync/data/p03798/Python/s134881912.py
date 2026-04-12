n = int(input())
s = input()

li = ["N"]*(n+1)

li[0] = "W"
li[1] = "W"

for i in range(1,n):
  if li[i]=="W" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
  
  elif li[i]=="S" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"
 
  elif li[i]=="W" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"

  elif li[i]=="S" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
     
if li[0]==li[n]:
  if s[0]=="o" and li[1]!=li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()
  if s[0]=="x" and li[1]==li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()

li[0] = "W"
li[1] = "S"

for i in range(1,n):
  if li[i]=="W" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
  
  elif li[i]=="S" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"
 
  elif li[i]=="W" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"

  elif li[i]=="S" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
      
if li[0]==li[n]:     
  if s[0]=="o" and li[1]!=li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()
  if s[0]=="x" and li[1]==li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()

li[0] = "S"
li[1] = "W"

for i in range(1,n):
  if li[i]=="W" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
  
  elif li[i]=="S" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"
 
  elif li[i]=="W" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"

  elif li[i]=="S" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
      
if li[0]==li[n]:     
  if s[0]=="o" and li[1]==li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()
  if s[0]=="x" and li[1]!=li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()

li[0] = "S"
li[1] = "S"

for i in range(1,n):
  if li[i]=="W" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
  
  elif li[i]=="S" and s[i]=="o":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"
 
  elif li[i]=="W" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "W"
    else:
      li[i+1] = "S"

  elif li[i]=="S" and s[i]=="x":
    if li[i-1] == "W":
      li[i+1] = "S"
    else:
      li[i+1] = "W"
      
if li[0]==li[n]:     
  if s[0]=="o" and li[1]==li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()
  if s[0]=="x" and li[1]!=li[n-1]:
    print(str(li[0:n]).replace("[","").replace("]","").replace(",","").replace("'","").replace(" ",""))
    exit()
    
print(-1)