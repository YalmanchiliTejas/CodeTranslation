aandb=(raw_input()).split(" ")
a=int(aandb[0])
b=int(aandb[1])

print "a",

if a > b:
    print ">",
elif a < b:
    print "<",
else:
    print "==",

print "b"