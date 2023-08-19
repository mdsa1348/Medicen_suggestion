#include <iostream>
#include <fstream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void Fracture();
void Physical_unusual_growth();
void Disease();
void Blood_survice();
void password();
void opptions();

struct Blood
{
    char nm[20];
    string pn, adr, bg, dt;
    // Blood():nm(""),pn(""),adr(""),bg("") {}

    void info()
    {
        cout << "Enter your short name : "; /*gets(nm);getline(cin,nm);cin>>nm;*/
        cin >> nm;
        // getchar();
        cout << "Enter your phone num : ";
        cin >> pn;
        // getchar();
        cout << "Enter your address(without space) : ";
        cin >> adr;
        // getchar();
        cout << "Enter your bg : ";
        cin >> bg;
        cout << "Enter your last date of donate(d/m/y) : ";
        cin >> dt;
        // getchar();
    }

    void display()
    {
        cout << "\nName : " << nm;
        cout << "\nPhone num : " << pn;
        cout << "\nAddress : " << adr;
        cout << "\nBlood group : " << bg;
        cout << "\nLast date of donate(d/m/y) : " << dt;
        // cout<<"\n";
    }
};

main()
{

    // cout << "hello \n";
    // printf("hello \n");

    cout << "\n\n\nHello guy's, SABBIR here. \n"
         << "i am here as your medical guider. "
         << "i am here to help you with your physical problem .\n"
         << "please tell us your problems. "
         << endl;

    int x = 0;
    while (x != 1)
    {
        password();
    }
    // we can use 'continue' in password opption to avoid calling opptions() inside of password

    opptions();
}

void opptions()
{
    system("color 07");
    int x = 0;
    char problems;

    do
    {

        cout << "\n\n========================:: Medicen_suggestion >> opption \n";
        cout << ""
             << "\nSome problems are given below in options : \n"
             << " 1. Fracture   \n "
             << "2. Physical unusual growth   \n "
             << "3. Disease \n"
             << " 4. Blood_survice \n"
             << " 5. Clear screan  \n"
             << " 6. Exit the project  \n"
             << "please select an opption : \n"
             << "=========================\n"
             << "as (1,2,3...) : ";
        cin >> problems;
        cout << "=========================\n";

        switch (problems)

        {

        case '1':
            Fracture();

            break;
        case '2':
            Physical_unusual_growth();

            break;
        case '3':
            Disease();

            break;
        case '4':
            system("cls");
            // fflush(stdin);
            Blood_survice();

            break;
        case '5':
            system("cls");
            break;
        case '6':
            exit(0);

            break;
        getch();
        default:
            cout << "Enter an valid opption : ";
        }
    } while (x != 1);
}

void Blood_survice()
{
    cout << "\n========================:: Medicen_suggestion >> opption >> Blood_survice ";
    Blood b;
    int i, j = 0;

    while (j != 1)
    {

        cout << "\n======================================================";
        cout << "\n1.Add member \n2.Search member by blood group\n3.Search member by name\n4.Search member by address\n5.Delete any members data \n"
             << "6.clear screen\n7.Return to main menu\n";
        cout << "=========================\n";
        cout << "Enter an option : ";
        cin >> i;
        cout << "=========================\n";

        if (i == 1)
        {
            b.info();
            ofstream f("sabbir_blood.dat", ios::app);
            fflush(stdin);
            f.write((char *)&b, sizeof(b));
            f.close();
            b.display();
        }

        if (i == 2)
        {

            string bldg;
            int a = 0;
            cout << "enter your blood group : ";             
            cin >> bldg;
            int k = 0;
            cout << "=========================\n";
            ifstream l("sabbir_blood.dat");
            fflush(stdin);
            while (l.read((char *)&b, sizeof(b)))
            {

                if (bldg == b.bg)
                {

                    k++;
                }
            }
            // cout<<"\n=========================";
            cout << "\nyou have : " << k << " member.";
            cout << "\n=========================";

            l.close();

            ifstream u("sabbir_blood.dat");

            while (u.read((char *)&b, sizeof(b)))
            {
                if (bldg == b.bg)
                {
                    cout << "=========================\n";
                    b.display();

                    cout << "\n=========================";
                    a = 1;
                }
                // break;
            }
            u.close();
            if (a == 0)
            {
                cout << "\nInvalid blood group...\n";
            }
        }

        if (i == 3)
        {
            string name;
            cout << "enter your name : ";
            cin >> name;
            ifstream u("sabbir_blood.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (name == b.nm)
                {
                    b.display();
                }
            }
            u.close();
        }

        if (i == 4)
        {
            string dis;
            cout << "enter your district : ";
            cin >> dis;
            ifstream u("sabbir_blood.dat");
            while (u.read((char *)&b, sizeof(b)))
            {
                if (dis == b.adr)
                {
                    b.display();
                }
            }
            u.close();
        }
        if (i == 5)
        {
            ifstream f("sabbir_blood.dat", std::ios::in | std::ios::binary);
            ofstream t("temp.dat", ios::binary | std::ios::out);

            if (!f || !t)
            {
                cout << "file not open.";
            }
            else
            {
                string name;
                cout << "enter your name : ";
                cin >> name;

                while (f.read((char *)&b, sizeof(b)))
                {
                    cout << "working....";
                    if (b.nm != name)
                    {

                        t.write((char *)&b, sizeof(b));
                    }
                }
                f.close();
                t.close();
                remove("sabbir_blood.dat");
                rename("temp.dat", "sabbir_blood.dat");
            }
        }

        if (i == 6)
        {
            system("cls");
        }
        if (i == 7)
        {
            opptions();
        }
        
    }
}

void password()
{
    system("color 47");
    int i = 0;
    char ch, st[21], ch1[21] = {"pass"};
    cout << "\n\t\tEnter Password : ";
    while (1)
    {
    ch = getch();
        if (ch == 13)
        {
            st[i] = '\0';
            //cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
            break;
        }
        else if (ch == 8 && i > 0)
        {
            i--;
            cout << "\b \b";
        }
        else
        {
            cout << "*";
            st[i] = ch;
            i++;
        }
    }
    ifstream inf("password.txt");
    inf >> ch1;
    inf.close();
    for (i = 0; st[i] == ch1[i] && st[i] != '\0' && ch1[i] != '\0'; i++)
        ;
    if (st[i] == '\0' && ch1[i] == '\0')
    {
        system("cls");
        opptions();
    }
    else
    {
        cout << "\n\n\t\tWrong Password.\n\n\t\ttry again.....\n";
        getch();
        system("cls");
        //getc();
    }
}

void Physical_unusual_growth()
{
    cout << ":: Medicen_suggestion >> opption >> Physical_unusual_growth";
    cout << "\n\n==============";
    cout << "||Coming soon||";
    cout << "==============\n\n";
}

void Fever(), Headache(), Snivel_or_cuff(), Acidity();

void Disease()
{
    cout << "\n========================:: Medicen_suggestion >> opption >> Disease ";
    char problems;
    int x = 0;

    do
    {

        cout << "\n\nSome problems are given below in options : \n"
             << " 1. Fever   \n "
             << "2. Headache   \n "
             << "3. Snivel or cuff \n"
             << " 4. Acidity \n"
             << " 5. Clear screan  \n"
             << " 6. Exit the project  \n"
             << " 7.Return to home page\n"
             << "======================================\n"
             << "please select an opption as (1,2,3...) : ";
        cin >> problems;
        cout << "======================================\n";

        // jokhon back jabo oita kivabe kaj korbe...step by stape thakbe ? na change hobe...
        // run a problem..
        // bangla typing..

        switch (problems)

        {

        case '1':
            Fever();

            break;
        case '2':
            Headache();

            break;
        case '3':
            Snivel_or_cuff();

            break;
        case '4':
            Acidity();

            break;
        case '5':
            system("cls");
            break;
        case '6':
            exit(0);

            break;
        case '7':
            opptions();

            break;

        default:
            cout << "Enter an valid opption : ";
        }
    } while (x != 1);
}

void Fever()
{
    cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Fever \n\n";
    string s1;

    ifstream

        myfile("Fever.txt");
    int i, j;
    cout << "Enter any opption by your age.";
    cout << "\n1.For (0-3 months)baby.\n2.For (3-6 months)baby\n3.For (6-24 months)baby\n4.For (2-17 year) young human \n5.For (18 year and above) \n"
            "6.Return to Disease \n";
    cout << "\n========================\n";
    cout << "Enter an opption : ";
    cin >> j;
    cout << "=========================\n";

    cout << "\n";

    for (i = 1; i <= 5; i++)
    {

        getline(myfile, s1);
        if (i == j)
        {
            cout << s1;
            // cout<<"\n";
            break;
        }

        // getchar();
    }

    if (j == 6)
    {
        Disease();
    }

    cout << "\n\n";
    Fever();
    myfile.close();
}

void Headache()
{
    cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Headache \n";

    cout << "\nHeadaches are a very common condition that most people will experience many times during their lives. The main symptom of a headache is pain in your head or face. There are several types of headaches\n and tension headaches are the most common. While most headaches aren�t dangerous, certain types can be a sign of a serious underlying condition.";

    cout << "\n\nNow check those options carefully : \n\n";
    cout << "> Sensitivity to light, noise and odors.\n"
         << "> Nausea and vomiting, upset stomach and abdominal pain.\n"
         << "> Loss of appetite.\n"
         << "> Feeling very warm (sweating) or cold (chills).\n"
         << "> Pale skin color (pallor).\n"
         << "> Feeling tired.\n"
         << "> Dizziness and blurred vision.\n"
         << "> Tender scalp.\n"
         << "> Diarrhea (rare).\n"
         << "> Fever (rare).\n";
    cout << "\n1.If you have more then 5 sin-toms on your body \n2.If you dont have more then 3,4 sintoms \n3.If you had any past accident \n4.Return to Disease ";
    int i;
    cout << "\n=================\n";
    cout << "Enter an opption : ";
    cin >> i;
    cout << "=================\n";

    cout << "\n";

    if (i == 1)
    {
        cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> migraine \n";

        cout << "\nIf you have more then 5 symbols , u have higher possibilities of migraine.\n";
        cout << "1.why it happens .\n"
             << "2.popular medicine of migraine\n"
             << "3.full complete details about it .\n"
             << "4.Exit headache.\n";
        int j;
        cout << "\n======================\n";
        cout << "Enter an option(1,2,3) : ";
        cin >> j;
        cout << "=====================\n";
        cout << "\n";
        if (j == 1)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> migraine >> why it happens \n";

            cout << "\n1.Changing weather conditions such as storm fronts, barometric pressure changes, strong winds or changes in altitude."
                    "\n2.Being overly tired. Overexertion.Dieting, or not drinking enough water."
                    "\n3.Changes in your normal sleep pattern."
                    "\n4.Loud noises."
                    "\n5.Exposure to smoke, perfumes or other odors."
                    "\n6.Certain medications cause blood vessels to swell.";
        }
        if (j == 2)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> migraine >> popular medicine of migraine \n";
            cout << "\nThree over-the-counter products approved by the Food and Drug Administration for migraine headaches are: \n"
                 << "i.Excedrin� Migraine.\n"
                 << "ii.Advil� Migraine.\n"
                 << "iii.Motrin� Migraine Pain.\n"
                 << "\nBe cautious when taking over-the-counter pain relieving medications. Sometimes overusing them can cause analgesic-rebound \n"
                    " headaches or a dependency problem. If you're taking any over-the-counter pain medications more than two to three times a week, \n"
                    "report that to your healthcare provider. They may suggest prescription medications that may be more effective.\n";
        }
        if (j == 3)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> migraine >> Full complete details about it \n";
            cout << "\nthere is an link bellow, you will gwt all the details.\n"
                 << "https://my.clevelandclinic.org/health/diseases/5005-migraine-headaches";
        }
        if (j == 4)
        {
            Disease();
        }
    }
    if (i == 2)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> normal headache \n";
        cout << "\nIf you don't have those sintoms then it must be normal headache.\n";

        cout << "1.why it happens .\n"
             << "2.popular medicine of headache\n"
             << "3.full complete details about it .\n"
             << "4.Exit headache.\n";
        int j;
        cout << "Enter an option(1,2,3) : ";
        cin >> j;
        cout << "\n";
        if (j == 1)
        {
            cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> normal headache >> why it happens\n";
            cout << "\nEye strain, such as from staring at a computer screen for a long time.\n"
                 << "Pain in other parts of your head and neck caused by problems such as temporomandibular disorders.\n"
                 << "Problems sleeping, such as insomnia.\n"
                 << "Stress related to family, work or life challenges, such as starting or losing a job or juggling too many commitments.\n"
                 << "Researchers haven�t identified one single cause for tension headaches. This headache type is not hereditary (run in families).\n"
                 << "Some healthcare providers believe tightened muscles in the back of your head or neck may trigger (bring on) tension headaches. \n";
        }
        if (j == 2)
        {
            cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> normal headache >> popular medicine of headache\n";
            cout << "\nIf you get a tension headache every so often, over-the-counter pain relievers may effectively treat your pain. Your provider may recommend you first try one of these options to relieve your symptoms:\n"

                 << "Acetaminophen (Tylenol�).\n"
                 << "Aspirin.\n"
                 << "Ibuprofen (Advil�, Motrin�).\n"
                 << "Naproxen sodium (Aleve�)\n";
        }
        if (j == 3)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> normal headache >> full complete details about it\n";
            cout << "\nThere is an link bellow, you will get all the details.\n"
                 << "https://my.clevelandclinic.org/health/diseases/8257-tension-type-headaches";
        }
        if (j == 4)
        {
            Disease();
        }
    }

    if (i == 3)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> Head Injury \n";
        cout << "\n1.Check when you immediate need to see a doctor \n"
             << "2.Check hospital and doctor details\n"
             << "3.Return to Head injury \n"
             << "4.Exit headache.\n";
        int j;
        cout << "\n========================\n";
        cout << "Enter an opption : ";
        cin >> j;
        cout << "=========================\n";
        cout << "\n";
        if (j == 1)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> Head Injury >> Immediate need to see a doctor \n";
            cout << "\nIf you or your child has any of these headache symptoms, get medical care right away : \n"
                 << "1.A sudden, new and severe headache.\n"
                 << "2.Headache with a fever, shortness of breath, stiff neck or rash.\n"
                 << "3.Headaches that occur after a head injury or accident.\n"
                 << "4.Getting a new type of headache after age 55.\n\n"
                 << "Also seek medical care right away if your headache is associated with neurological symptoms, such as:  \n"
                 << "5.Weakness.\n"
                 << "6.Dizziness.\n"
                 << "7.Sudden loss of balance or falling.\n"
                 << "8.Numbness or tingling.\n"
                 << "9.Paralysis.\n"
                 << "10.Speech difficulties.\n"
                 << "11.Mental confusion.\n"
                 << "12.Seizures.\n"
                 << "13.Personality changes/inappropriate behavior.\n"
                 << "14.Vision changes (blurry vision, double vision or blind spots).\n";
        }

        if (j == 2)
        {
            cout << "=========================:: Medicen_suggestion >> opption >> Disease >> Headache >> Head Injury >> Check hospital and doctor details \n";
            cout << " \n01. Professor Dr. Kazi Deen Mohammad\nMBBS, FCPS, Neurology (MD)\n While talking about the best neurologists in Dhaka, the name, Professor Kazi Deen Mohammad comes first. He is a professor at the National Institute of Neuroscience. He was once a professor and principal of Dhaka Medical College. He gives treatment for anxiety, headache, migraine, and other neurological diseases. His chamber is open from 4 pm to 8 pm. Besides, he keeps his chamber closed on Thursday, Friday, and other government holidays.\nChamber Information:Address: APRC & General Hospital, 135, New Eskaton Road, Dhaka Bangladesh\nContact for serial: +88029339089, 029342744\n\n"
                 << " 02. Prof. Dr. Md. Amirul Haque\nMBBS (DMC), FCPS (BD), FRCP (Glasgow), FACP (USA), DCN (London)\nHe was the head of Neuro-medicine at BIRDEM & IMC. Besides, he is a former professor at Ibrahim Medical College. He has a lot of achievements. There is no doubt he is one of the most prominent neurologists in Dhaka. Dr. MD. Amirul is a member of the American Academy of Neurology. He sits in his chamber in Bangladesh Specialized Hospital.\nChamber Information:\nAddress: Bangladesh Specialized Hospital, Shyamoli, Mirpur Road, Dhaka 1207\nContact Info: 10633 or +8809666700100 (Hotline)\n\n"
                 << " 03. Professor Dr. Md. Abdul Hai\nMBBS, FCPS (Medicine), Ph.D. (India), FRCP (Edinburg), Fellow (Interventional Neurology)\nProfessor Dr. Md. Abdul Hai is also a renowned neurologist in Dhaka. Now he has been working as a professor at Sir Salimullah College and Mitford Hospital. His name and fame have flourished across the country. He sees his patients at his chamber in Ibn Sina Diagnostic & Imaging Center, Dhanmondi\nChamber Information:\nAddress: Ibn Sina Diagnostic & Imaging Center, House #48, Road 9/A, Satmasjid Road, Dhanmondi, Dhaka 1209\nContact for serial: +88029126625-6, 01717351631, 029128835-7\n\n"
                 << " 04.Dr. Md. Munzur Elahi\nMBBS, MD (Neurology)\nBrain, Nerve, Spine, Neurology & Medicine Specialist\nRajshahi Medical College & Hospital\n1 Star2 Stars3 Stars4 Stars5 Stars (24)\nChamber & Appointment\nPopular Diagnostic Center, Rajshahi\nAddress: House # 474, Chowdhury Tower, Laxmipur, Rajshahi\nVisiting Hour: 6pm to 9pm (Closed: Friday)\nAppointment: +8809613787811\nChamber Information\nIslami Bank Hospital, Rajshahi\nAddress: Medical Mor, Laxmipur, Rajshahi � 6000\nVisiting Hour: 3pm to 6pm (Closed: Friday)\nContact Number: +8801777242536\n\n"
                 << " 5.Dr. Achinta Kumar Mallick\nMBBS, BCS (Health), MD (Neuromedicine)\nNeuromedicine Specialist\nRajshahi Medical College & Hospital\n1 Star2 Stars3 Stars4 Stars5 Stars (3)\nChamber & Appointment\nMedipath Diagnostic Complex, Rajshahi\nAddress: Shuvecca View, Greater Road, Laxmipur, Kajihata, Rajshahi\nVisiting Hour: Unknown. Please call to know visiting hour\nAppointment: +8801712685297\n\n";
        }
        if (j == 3)
        {
            i == 3;
        }
        if (j == 4)
        {
            Disease();
        }
    }
    if (i == 4)
    {
        Disease();
    }

    cout << "\n=============================================\n";
    return Headache();
}

void Snivel_or_cuff()
{
    cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Snivel_or_cuff \n";
    cout << "\n1.check details about snivel . \n"
         << "2.check details about cauff.\n"
         << "3.Return to disease.\n";
    ;

    int j;
    cout << "Enter an option(1,2,3) : ";
    cin >> j;
    cout << "\n";
    if (j == 1)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Snivel_or_cuff >> check details about snivel\n";
        cout << "\nWhat are cold and cough medicines?\n"
             << "\nCold and cough medicines can help relieve symptoms of a common cold. The symptoms of a cold can include a sore throat, stuffy or runny nose, sneezing, and coughing."

             << "You don't usually need to treat a cold or the cough that it causes. You can't cure a cold, and antibiotics won't help you get better. But sometimes the symptoms can keep you awake or cause a lot of discomfort. In that case, cold and cough medicines can sometimes be helpful."

             << "\nWhat are the different types of cold and cough medicines?"
             << "\nThere are lots of different cold and cough medicines, and they do different things:"

             << "\n\n>Nasal decongestants - unclog a stuffy nose"
             << "\n>Cough suppressants - quiet a cough"
             << "\n>Expectorants - loosen mucus in your lungs so you can cough it up"
             << "\n>Antihistamines - stop runny noses and sneezing"
             << "\n>Pain relievers - ease fever, headaches, and minor aches and pains"
             << "\n\nWhat do I need to know about taking cold and cough medicines?"
             << "\nBefore taking these medicines, read the labels and follow the instructions carefully. Many cold and cough medicines contain the same active ingredients. For example, some of them include pain relievers. If you are taking these medicines and are also taking a separate pain reliever, you could be getting a dangerous amount of the pain reliever."

             << "\nDo not give cold or cough medicines to children under two, and don't give aspirin to children."

             << "\n\nWhat else can I do to feel better for a cold or cough?"
             << "\nIf you decide that you don't want to take cold and cough medicines, there are other ways to feel better:"

             << "\nDrink lots of fluids"
             << "\nGet plenty of rest"
             << "\nUse a cool mist humidifier"
             << "\nUse saline nose drops or sprays"
             << "\nUse nasal suctioning with a bulb syringe, which can be very helpful in children under a year old"
             << "\n\n==================================================\n";
    }

    if (j == 2)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Snivel_or_cuff >> check details about cauff\n";
        cout << "\n\nThe runny nose, persistent stuffiness, and postnasal drip of the sniffles are often self-diagnosed as a cold. The common cold is a viral infection that most people recover from in a week to 10 days."

             << "\nCold symptoms vary from person to person. Along with the sniffles, symptoms may include:"

             << "\n>sore throat"
             << "\n>cough"
             << "\n>sneezing"
             << "\n>low-grade fever"
             << "\n\n The rhinoviruses that enter your body through your nose, mouth, or eyes are the most common causes of the common cold."
             << "Although your sniffles may indicate that you have a cold, they could be caused by another condition."

             << "\n\nWhat if it�s not a cold?"
             << "\nIf you�ve had the sniffles for weeks, or even months, your runny nose could be caused by a number of conditions."

             << "\n\nAllergies"
             << "\nAn allergy is a reaction by your immune system to a foreign substance or food that typically doesn�t cause a reaction in most other people. You might have an allergic reaction to:"

             << "\n>dust"
             << "\n>mold"
             << "\n>pet dander"
             << "\n>pollen"
             << "\n\nAllergic rhinitis (hay fever) is a common condition that�s characterized by a runny nose, congestion, and sneezing."

             << "Chronic sinus infections"
             << "\nYou�re considered to have chronic sinusitis when your sinuses (the spaces inside your nose and head) stay inflamed and swollen for 3 months or longer, even with treatment."

             << "\nNasal obstruction"
             << "\nA toddler�s sniffles may be caused by an obstruction they put up their nose, such as a bead or a raisin. Other blockages, for any age, could be:"

             << "\nDeviated septum. This is when the cartilage and bone divider in your nasal cavity is crooked or off center."
             << "\nEnlarged turbinates (nasal conchae). This is when the passageways that help moisten and warm the air flowing through your nose are too large and block air flow."
             << "\nNasal polyps. These are soft, painless growths on the lining of your sinuses or nasal passages. They are noncancerous but can block the nasal passages."
             << "\n\nNasal sprays"
             << "\nTo clear a stuffed-up nose, people often use over-the-counter (OTC) nasal sprays. According to the Cleveland Clinic, nasal sprays containing oxymetazoline can make congestion symptoms worse over time. They can also be addictive."

             << "\n\nNonallergic rhinitis"
             << "\nAlso called vasomotor rhinitis, nonallergic rhinitis doesn�t involve the immune system like allergic rhinitis does. It does, however, have similar symptoms, including runny nose."

             << "\n\nCould it be cancer?"
             << "\nAccording to the American Cancer SocietyTrusted Source, persistent runny nose and nasal congestion could be a sign of nasal cavity and paranasal sinus cancers, which are rare. Other symptoms of these cancers may include:"

             << "sinus infections that aren�t cured with antibiotics"
             << "\n>sinus headaches"
             << "\n>swelling or pain in the face, ears, or eyes"
             << "\n>persistent tearing"
             << "\n>decreased sense of smell"
             << "\n>numbness or pain in teeth"
             << "\n>nosebleeds"
             << "\n>a lump or sore inside the nose that won�t heal"
             << "\n>difficulty opening mouth"
             << "\n\nSometimes, especially in the early stages, people with nasal cavity or paranasal sinus cancer don�t exhibit any of these symptoms. Often, this cancer is diagnosed when treatment is being given for a benign, inflammatory disease, such as sinusitis."

             << "\nAccording to the American Cancer SocietyTrusted Source, nasal cavity and paranasal sinus cancers are rare, with about 2,000 Americans diagnosed annually."

             << "\n\nHow to treat the sniffles"
             << "\nTreatment for your sniffles will vary based on the cause."

             << "If you have a cold, the virus will typically run its course in a week to 10 days. Your sniffles should clear up in that time, too. If you need help managing the sniffles to make you more comfortable, there are a variety of OTC medications to treat cold symptoms."

             << "Look for a decongestant medication, which can help to temporarily dry up your sinuses. While these medications won�t treat the sniffles, they�ll offer temporary relief."

             << "You may also try taking a hot shower or bath to help loosen up mucus and help you not to feel as though it�s trapped in your sinuses. Loosening the mucus may temporarily make your nose run more, but it could help provide relief once you�ve cleared out some of the buildup."

             << "If your sniffles don�t respond to OTC or home remedies and last for over a month, visit your doctor for a full diagnosis and treatment recommendation."

             << "If your sniffles are caused by another underlying condition, your doctor may recommend other treatments, including:"

             << "\n>antibiotics, if you have a chronic sinus infection"
             << "\n>antihistamines and decongestants, if you have allergies or allergic rhinitis"
             << "\n>surgery to repair structural problems"
             << "\n>septoplasty to correct a deviated septum"
             << "\n>surgery to remove nasal polyps"
             << "\n>Takeaway"
             << "\nAlthough the sniffles are often thought to be a symptom of the common cold, they could be an indication of another condition, such as:"

             << "\n>allergies"
             << "\n>chronic sinus infection"
             << "\n>nasal obstruction"
             << "\n>nasal sprays"
             << "\n>nonallergic rhinitis"
             << "\n>In rare cases, the sniffles could also indicate nasal cavity or paranasal sinus cancer."

             << "\nIf the congestion and runny nose of your sniffles last for more than a month, see your doctor who might refer you to an otolaryngologist, or ENT, a doctor specializing in ear, nose, and throat."
             << "\n\n==================================================\n";
    }
    if (j == 3)
    {
        Disease();
    }
    Snivel_or_cuff();
}

void Acidity()
{
    cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Acidity\n";
    cout << "\nSome options about acidity is given below.\n";

    cout << "\n1.why it happens .\n"
         << "2.popular medicine of acidity\n"
         << "3.full complete details about it .\n"
         << "4.Exit headache.\n";
    int j;
    cout << "\n=========================\n";
    cout << "Enter an option(1,2,3) : ";
    cin >> j;
    cout << "=========================";
    cout << "\n";
    if (j == 1)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Acidity >> why it happens\n";
        cout << "\nEating large meals or lying down right after a meal\n"
             << "\nBeing overweight or obese\n"
             << "Eating a heavy meal and lying on your back or bending over at the waist\n"
             << "Snacking close to bedtime\n"
             << "Eating certain foods, such as citrus, tomato, chocolate, mint, garlic, onions, or spicy or fatty foods\n"
             << "RDrinking certain beverages, such as alcohol, carbonated drinks, coffee, or tea\n"
             << "Smoking\n"
             << "Being pregnant\n"
             << "Taking aspirin, ibuprofen, certain muscle relaxers, or blood pressure medications\n\n";
    }
    if (j == 2)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Acidity >> popular medicine of acidity\n";
        cout << "In many cases, lifestyle changes combined with over-the-counter medications are all you need to control the symptoms of acid reflux disease.\n"

             << "\nFoaming agents (Gaviscon) coat your stomach to prevent reflux.\n"
             << "H2 blockers (Pepcid, Tagamet) decrease acid production.\n"
             << "Proton pump inhibitors (Aciphex, Nexium, Prilosec, Prevacid, Protonix) also reduce the amount of acid your stomach makes.\n"
             << "Prokinetics (Reglan, Urecholine) can help strengthen the LES, empty your stomach faster, and reduce acid reflux.\n";
    }
    if (j == 3)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Disease >> Acidity >> full complete details about it\n";
        cout << "\nThere is an link bellow, you will get all the details.\n"
             << "https://www.webmd.com/heartburn-gerd/guide/what-is-acid-reflux-disease";
    }
    if (j == 4)
    {
        Disease();
    }
    Acidity();
}

void Fracture()
{
    cout << "\n\n=========================:: Medicen_suggestion >> opption >> Fracture \n";

    string s1;

    ifstream

        myfile("fracture.txt");
    int i, j, k;
    cout << "\n1.Symptoms of a fracture.\n2. First-aid care of fractures\n3.Diagnose bone fractures\n4.Self-care after a bone fracture\n5.Return main menu\n";
    cout << "\n========================\n";
    cout << "Enter an opption : ";
    cin >> j;
    cout << "=========================\n";

    cout << "\n";
    if (j == 1)
    {
        cout << "=========================:: Medicen_suggestion >> opption >> Fracture >> Symptoms of a fracture \n\n";
        for (i = 1; i <= 9; i++)
        {
            getline(myfile, s1);

            cout << s1;
            cout << "\n";
        }
    }

    if (j == 2)
    {
        cout << "\n\n=========================:: Medicen_suggestion >> opption >> Fracture >> First-aid care of fractures\n\n";
        for (i = 1; i <= 27; i++)
        {
            getline(myfile, s1);
            if (i > 9 && i <= 27)
            {
                cout << s1;
                cout << "\n";
            }
        }
    }
    if (j == 3)
    {
        cout << "\n\n=========================:: Medicen_suggestion >> opption >> Fracture >> Diagnose bone fractures\n\n";
        for (i = 1; i <= 40; i++)
        {
            getline(myfile, s1);
            if (i > 27 && i <= 40)
            {
                cout << s1;
                cout << "\n";
            }
        }
    }
    if (j == 4)
    {
        cout << "\n=========================:: Medicen_suggestion >> opption >> Fracture >> Self-care after a bone fracture\n\n";
        for (i = 1; i <= 50; i++)
        {
            getline(myfile, s1);
            if (i > 40 && i <= 50)
            {
                cout << s1;
                cout << "\n";
            }
        }
    }
    if (j == 5)
    {
        opptions();
    }
    myfile.close();
    Fracture();
}
