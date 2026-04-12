# get input from user and convert in to int
current_temp = int(input())

# Check that the restriction per task instruction is met
if (current_temp <= 40) and (current_temp >= -40):
    # Check if current_temp is greater than or equal to 30
    if current_temp >= 30:
        print("Yes")
    else:
        print("No")