def test_cases(cases: list) -> str:
	if cases[0] == cases[1]:
		return "Yes"
	return "No"

case = input()
cases = case.split()
print(test_cases(cases))