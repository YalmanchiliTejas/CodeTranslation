
from sys import stdin
import sys

def getInputs():
	inputs=[]
	for line in stdin:
		line=line.split()
		inputs.append(line)
	return inputs


def main(inputs):
	s=inputs[0][0]
	if "A" in s and "B" in s:
		print("Yes")
		sys.exit(0)
	print("No")
			
		
	
	
	

if __name__=="__main__":
	inputs=getInputs()
# 	inputs=simInputs()
	main(inputs)
	
