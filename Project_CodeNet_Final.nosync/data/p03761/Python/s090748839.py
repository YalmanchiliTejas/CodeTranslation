n = int(raw_input())
list_str = []
for count in range(0,n):
    list_str.append(raw_input())
if n != 1:
	for count in range(0,n):
	    if count == 0:
	        output = set(list_str[count])
	    else:
	        compare1 = set(output)
	    	compare2 = set(list_str[count])
	    	output = list(compare1 & compare2)

	tmp_output = ""
	
	for count1 in range(0,len(output)):
		#print output[count1]
		min = 1000
		for count2 in range(0,n):
			num = list_str[count2].count(output[count1])
			if num < min:
				min = num
			#print min
		tmp_output += min*output[count1]
	output = tmp_output
	#output.sort()
else:
	output = list_str[0]
output = sorted(output)
output = ''.join(output)
print output