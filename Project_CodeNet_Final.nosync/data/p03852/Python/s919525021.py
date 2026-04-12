dbflag=""

def debug(*args):
	if ""!=dbflag: print(*args)

if ""!=dbflag: _INDATA=open(dbflag)

def readline():
	if ""!=dbflag:return _INDATA.readline()
	else: return input()


result = -1

c = readline().rstrip()

BOIN = {'a','i','u','e','o'}


if c in BOIN:
	result = "vowel"
else:
	result = "consonant"

print(result)
